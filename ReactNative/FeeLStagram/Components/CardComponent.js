import React, { Component } from "react";
import { View, Image, Text, StyleSheet } from "react-native";
import {
  Card,
  CardItem,
  Thumbnail,
  Body,
  Left,
  Right,
  Button,
  Icon
} from "native-base";

export default class CardComponent extends Component {
  render() {
    return (
      <Card>
        <CardItem>
          <Left>
            <Thumbnail
              source={{
                uri:
                  "https://scontent-gmp1-1.xx.fbcdn.net/v/t1.0-1/p320x320/1390634_638637912847458_869916414_n.jpg?_nc_cat=105&_nc_oc=AQkVpOOh3EJOOFrluL8B8HvPkQLaZHODp3A-SSeDiry9Koyx5tycQ53rvtX4qtzjoLc&_nc_ht=scontent-gmp1-1.xx&oh=37c644078bbea929ba83beff9168da71&oe=5DA8A878"
              }}
            />
            <Body>
              <Text>mesikkera</Text>
              <Text note>Jul 25, 2019</Text>
            </Body>
          </Left>
        </CardItem>
        <CardItem cardBody>
          <Image
            source={{
              uri:
                "https://scontent-gmp1-1.xx.fbcdn.net/v/t1.0-9/31349717_2131985657077337_1594449580064243712_n.jpg?_nc_cat=104&_nc_oc=AQlwOH-A36ImmDpLS8fiNhogMYQgGuiRFfgT8t86XcDAz6g8dYCfcJVs8j655MQVRNY&_nc_ht=scontent-gmp1-1.xx&oh=2967dbae5045e9e8d229cd721dd73395&oe=5DAE5925"
            }}
            style={{ height: 200, width: null, flex: 1 }}
          />
        </CardItem>
        <CardItem style={{ height: 45 }}>
          <Left>
            <Button transparent>
              <Icon name="ios-heart" style={{ color: "black" }} />
            </Button>
            <Button transparent>
              <Icon name="ios-chatbubbles" style={{ color: "black" }} />
            </Button>
            <Button transparent>
              <Icon name="ios-send" style={{ color: "black" }} />
            </Button>
          </Left>
        </CardItem>
        <CardItem style={{ height: 20 }}>
          <Text>101 likes</Text>
        </CardItem>
        <CardItem>
          <Text>
            <Text style={{ fontWeight: "900" }}>mesikkera </Text>
            리엑트 네이티브로 구현하는 필스타그램
          </Text>
        </CardItem>
      </Card>
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
