import React, { Component } from "react";
import logo from "./logo.svg";
import "./App.css";
import LedController from "./components/ledcontroller";
import TempSensor from "./components/tempsensor";
import FirmwareUpload from "./components/firmwareUpload";
import axios from "axios";
import { Tabs, Tab } from "react-bootstrap-tabs";

class App extends Component {
  constructor(props) {
    super(props);
    this.state = {
      sensor: {
        id: 1,
        type: "temperature",
        units: "°C",
        value: 0.0,
      },
    };
  }

  componentDidMount() {
    // Ajax Call
    console.log("App - componentDidMount");

    setInterval(this.getData, 2500);
  }

  getData = () => {
    axios
      .get("/API/gettemp")
      .then((response) => {
        const sensor = this.state.sensor;

        sensor.value = response.data.value;

        this.setState({ sensor: sensor });
      })
      .catch((e) => {
        console.log(e);
      });
  };

  render() {
    return (
      <React.Fragment>
        <div className="gbackground">
          <img src="logo.svg" className="top-logo"></img>
        </div>
        <div className="outer-main-content">
          <div className="main-content">
            <Tabs
              defaultActiveKey="home"
              transition={false}
              id="noanim-tab-example"
            >
              <Tab eventKey="home" label="Home">
                <LedController />
                <TempSensor sensor={this.state.sensor} />
                <div style={{ textAlign: "left" }}>
                  <ul>
                    <li>
                      Mauris cursus orci fringilla, elementum arcu et, faucibus
                      quam.
                    </li>
                    <li>Phasellus ut orci sed nisi pellentesque blandit.</li>
                    <li>Duis tincidunt dui eget maximus blandit.</li>
                    <li>Fusce volutpat nisi in libero eleifend dignissim.</li>
                    <li>Proin elementum ex sed congue ultrices.</li>
                  </ul>
                </div>
              </Tab>
              <Tab eventKey="config" label="Config">
                <br></br>
                <FirmwareUpload />
                <br></br>

                <img src={logo} className="App-logo" alt="logo" />
              </Tab>
            </Tabs>
          </div>
        </div>
        <div className="bottom-note">
          <p>
            Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris
            massaante, euismod non dignissim eget, ornare eget ante.
          </p>
        </div>
      </React.Fragment>
    );
  }
}

export default App;
