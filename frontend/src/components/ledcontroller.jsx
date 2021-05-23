import React, { Component } from "react";
import axios from "axios";

class LedController extends Component {
  state = {};

  handleLedOnClick() {
    // POST request using fetch with set headers
    const article = { title: "React POST Request Example" };
    axios
      .post("/API/ldon", article)
      .then((response) => this.setState({ articleId: response.data.id }));
  }

  handleLedOffClick() {
    // POST request using fetch with set headers
    const article = { title: "React POST Request Example" };
    axios
      .post("/API/ldoff", article)
      .then((response) => this.setState({ articleId: response.data.id }));
  }

  render() {
    return (
      <React.Fragment>
        <button
          onClick={() => this.handleLedOnClick()}
          className="btn btn-light badge-pill m-2"
        >
          LedOn
        </button>
        <button
          onClick={() => this.handleLedOffClick()}
          className="btn btn-light badge-pill m-2"
        >
          LedOff
        </button>
      </React.Fragment>
    );
  }
}

export default LedController;
