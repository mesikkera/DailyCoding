/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow
 */

import React, { Component } from "react";
import { StyleSheet, Text, View } from "react-native";
import { createStackNavigator, createAppContainer } from "react-navigation";
import MainScreen from "./Components/MainScreen";

const AppStackNavigator = createStackNavigator({
  Main: {
    screen: MainScreen //MainScreen 컴포넌트를 네비케이터에 등록
  }
});
