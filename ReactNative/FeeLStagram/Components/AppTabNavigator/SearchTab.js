import React, { Component } from "react";
import { View, Text, StyleSheet } from "react-native";
import { Icon, Content, Container, Header } from "native-base";
import { WebView } from "react-native-webview";

export default class ProfileTab extends Component {
  static navigationOptions = {
    tabBarIcon: ({ tintColor }) => (
      <Icon name="ios-search" style={{ color: tintColor }} />
    )
  };
  render() {
    return (
      <Container style={{}}>
        <Header />
        <WebView
          source={{
            uri: "http://www.feelway.com/m/index.php"
          }}
          style={{ marginTop: 20 }}
        />
      </Container>
    );
  }
}

const style = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: "center",
    justifyContent: "center"
  }
});
