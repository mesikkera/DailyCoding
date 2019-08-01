import React, { Component } from "react";
import { View, Text, StyleSheet, Image } from "react-native";
import {
  Icon,
  Container,
  Content,
  Header,
  Left,
  Body,
  Right,
  Button
} from "native-base";

export default class ProfileTab extends Component {
  static navigationOptions = {
    tabBarIcon: ({ tintColor }) => (
      <Icon name="person" style={{ color: tintColor }} />
    )
  };
  render() {
    return (
      <Container style={{ flex: 1, backgroundColor: "White" }}>
        <Header>
          <Left>
            <Icon name="md-person-add" style={{ paddingLeft: 10 }} />
          </Left>
          <Body>
            <Text>mesikkera</Text>
          </Body>
          <Right />
        </Header>
        <Content>
          <View style={{ flexDirection: "row", paddingTop: 10 }}>
            <View style={{ flex: 1, alignItems: "center" }}>
              <Image
                source={{
                  url:
                    "https://scontent-gmp1-1.xx.fbcdn.net/v/t1.0-1/p320x320/1390634_638637912847458_869916414_n.jpg?_nc_cat=105&_nc_oc=AQna_OqlVGPGCHUmKCBcfWynlqYPYBvoEC035lDh6zavgyb7iquphVX1LX1FMN7LEuk&_nc_ht=scontent-gmp1-1.xx&oh=3c3a20107b4ae87eba8fc8ec949b087d&oe=5DA8A878"
                }}
                style={{ width: 75, height: 75, borderRadius: 37.5 }}
              />
            </View>
            <View style={{ flex: 3 }}>
              <View
                style={{ flexDirection: "row", justifyContent: "space-around" }}
              >
                <View style={{ alignItems: "center" }}>
                  <Text>167</Text>
                  <Text style={{ fontSize: 10, color: "gray" }}>posts</Text>
                </View>
                <View style={{ alignItems: "center" }}>
                  <Text>346</Text>
                  <Text style={{ fontSize: 10, color: "gray" }}>follower</Text>
                </View>
                <View style={{ alignItems: "center" }}>
                  <Text>192</Text>
                  <Text style={{ fontSize: 10, color: "gray" }}>following</Text>
                </View>
              </View>
              <View style={{ flexDirection: "row" }}>
                <Button
                  bordered
                  dark
                  style={{
                    flex: 4,
                    marginLeft: 10,
                    justifyContent: "center",
                    height: 30,
                    marginTop: 10
                  }}
                >
                  <Text>Edit Profile</Text>
                </Button>
                <Button
                  bordered
                  dark
                  small
                  icon
                  style={{
                    flex: 1,
                    marginRight: 10,
                    marginLeft: 5,
                    justifyContent: "center",
                    height: 30,
                    marginTop: 10
                  }}
                >
                  <Icon name="settings" />
                </Button>
              </View>
            </View>
          </View>
          <View style={{ paddingHorizontal: 10, paddingVertical: 10 }}>
            <Text style={{ fontWeight: "bold" }}>오지윤</Text>
            <Text>James | Programmer | Data Scientist</Text>
            <Text>www.feelway.com</Text>
          </View>
          <View
            style={{
              flexDirection: "row",
              justifyContent: "space-around",
              borderTopWidth: 1,
              borderTopColor: "#eae5e5"
            }}
          >
            <Button transparent>
              <Icon name="ios-apps" />
            </Button>
            <Button transparent>
              <Icon name="ios-list" />
            </Button>
            <Button transparent>
              <Icon name="ios-people" />
            </Button>
            <Button transparent>
              <Icon name="ios-bookmark" />
            </Button>
          </View>
        </Content>
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
