#include <Arduino.h>
#include <FS.h>
#include <SD.h>

#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

void handleUpload(AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final);

void notFoundResponse(AsyncWebServerRequest *request)
{
    request->send(404, "text/plain", "Not found");
}

void setup_webserver(){
  Serial.println("Setting up HTTP server...");

  //server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
  //request->send(SD_MMC, "/index.html", "text/html");
  //});

  Serial.println("Setup API routes methods...");
  // API routes methods
  server.on("/API/ldon", HTTP_POST, [](AsyncWebServerRequest *request){

    request->send(200, "application/json", "{\"ack\":\"led on\"}");
  });

  server.on("/API/ldoff", HTTP_POST, [](AsyncWebServerRequest *request){

    request->send(200, "application/json", "{\"ack\":\"led off\"}");
  });

  server.on("/API/gettemp", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "application/json", "{\"value\":\"" + String(25.4) + "\"}");
  });

  // handling uploading firmware file
  server.on("/update", HTTP_POST, [](AsyncWebServerRequest *request) {}, handleUpload);

  server.onNotFound(notFoundResponse);

  // Static file serve
   Serial.println("Setup static file server...");
  server
    .serveStatic("/", SD, "/")
    .setDefaultFile("index.html");
  
  Serial.println("Starting HTTP server...");
  server.begin();
  Serial.println("HTTP started");
}

File tempfile;
// handle the upload of the firmware
void handleUpload(AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final){
  if(!index){
    Serial.println((String)"UploadStart: " + filename);
    // open the file on first call and store the file handle in the request object

    // Faire un if et delete si le fichier existe

    // Mettre un IF ici pour le "/"
    SD.remove("/"+filename);

    tempfile = SD.open("/"+filename, "w");
  }
  if(len) {
    // stream the incoming chunk to the opened file
    tempfile.write(data,len);
  }
  if(final){
    Serial.println((String)"UploadEnd: " + filename + "," + (index+len));
    // close the file handle as the upload is now done
    tempfile.close();
    request->send(200, "text/plain", "File Uploaded !");
  }
}
