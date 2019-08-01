import React, { Component } from "react";
import { WebView } from "react-native";

export  class default App extends Component {
  render() {
    return (
      <WebView
        source={{ uri: "http://www.feelway.com/m" }}
        style={{ marginTop: 20 }}
      />
    );
  }
}
