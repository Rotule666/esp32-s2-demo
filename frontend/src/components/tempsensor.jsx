import React, { Component } from "react";
import reactDom from "react-dom";

class TempSensor extends Component {
  state = { tempsensor: "" };
  render() {
    return (
      <React.Fragment>
        <h5>
          <badge className="badge-primary badge-pill m-2">
            {this.props.sensor.value} {this.props.sensor.units}
          </badge>
        </h5>
        <br></br>
      </React.Fragment>
    );
  }
}

export default TempSensor;
