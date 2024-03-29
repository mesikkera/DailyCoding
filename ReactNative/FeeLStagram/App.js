/**
 * FeeLStagram
 * www.feelway.com/m
 *
 * @author: mesikkera
 * @date: 2019.07.25
 */
import React, { Component } from "react";
import { StyleSheet, Text, View } from "react-native";
import { createStackNavigator, createAppContainer } from "react-navigation";
import MainScreen from "./Components/MainScreen";

const AppStackNavigator = createStackNavigator({
  Main: {
    screen: MainScreen
  }
});

export default createAppContainer(AppStackNavigator);
