import React, { Component } from "react";
import { StyleSheet, Platform, View, Text } from "react-native";
import { Icon } from "native-base";
import { createBottomTabNavigator, createAppContainer } from "react-navigation";

// 하단 탭에 들어갈 컴포넌트들
import HomeTab from "./AppTabNavigator/HomeTab";
import SearchTab from "./AppTabNavigator/SearchTab";
import AddMediaTab from "./AppTabNavigator/AddMediaTab";
import LikesTab from "./AppTabNavigator/LikesTab";
import ProfileTab from "./AppTabNavigator/ProfileTab";

// 하단 탭 네비게이터 생성
const AppTabNavigator = createBottomTabNavigator({
  HomeTab: { screen: HomeTab },
  SearchTab: { screen: SearchTab },
  AddMediaTab: { screen: AddMediaTab },
  LikesTab: { screen: LikesTab },
  ProfileTab: { screen: ProfileTab }
});

const AppTabContainet = createAppContainer(AppTabNavigator);

export default class MainScreen extends Component {
  //navigationOPtions 코드 추가
  static navigationOptions = {
    headerLeft: <Icon name="ios-camera" style={{ paddingLeft: 10 }} />,
    title: "FeeLstagram",
    headerRight: <Icon name="ios-send" style={{ paddingRight: 10 }} />
  };

  render() {
    return (
      <View style={styles.container}>
        <Text>MainScreen</Text>
      </View>
    );
  }

  render() {
    return <AppTabContainet />;
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: "center",
    justifyContent: "center"
  }
});
