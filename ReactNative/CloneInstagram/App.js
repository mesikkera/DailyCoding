/**
 * Instagram Clone
 * http://www.feelway.com
 *
 * @author: mesikkera
 * @date: 2019.07.24
 */

import React, { Component } from 'react';
import { StyleSheet, Text, View } from 'react-native';
import { createStactNavigator, createAppContainer } from 'react-navigation';
import MainScreen from './Components/MainScreen';

const AppStackNavigator = createAppContainer({
  Main: {
    screen: MainScreen, // MainScreen 컴포넌트를 네비게이터에 등록
  },
});

export default createAppContainer(AppStackNavigator);
