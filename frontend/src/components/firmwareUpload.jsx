import React, { Component } from "react";
import axios from "axios";

class FirmwareUpload extends Component {
  constructor(props) {
    super(props);
    this.state = {
      selectedFile: null,
    };
  }

  onChangeHandler = (event) => {
    this.setState({
      selectedFile: event.target.files[0],
      loaded: 0,
    });
  };

  onClickHandler = () => {
    const data = new FormData();
    data.append("file", this.state.selectedFile);

    axios.post("http://192.168.2.69/update", data, {}).then((res) => {
      // then print response status
      console.log(res.statusText);
    });
  };

  render() {
    return (
      <React.Fragment>
        <input type="file" multiple="" onChange={this.onChangeHandler} />
        <button
          type="button"
          className="btn btn-success btn-sm"
          onClick={this.onClickHandler}
        >
          Upload
        </button>
      </React.Fragment>
    );
  }
}

export default FirmwareUpload;
