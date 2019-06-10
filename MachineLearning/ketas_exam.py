from keras.datasets import mnist 
(train_images, train_labels), (test_images, test_labels) = mnist.load_data()

train_images.shape
print(train_images.shape)

from keras import models 
from keras import layers 

network = models.Sequential()
network.add(layers.Dense(512, activation='relu', input_shape=(28*28,)))
network.add(layers.Dense(10, activation='softmax'))

# 손실 함수(loss function): 훈련 데이터에서 신경망의 성능을 측정하는 방법으로 네트워크가 옳은 방향으로 학습될 수 있도록 도와준다.
# 옵티마이저(optimizer): 입력된 데이터와 손실 함수를 기반으로  네트워크를 업데이트 하는 메커니즘
# 훈련과 테스트 과정을 모니터링할 지료: 여기에서는 정확도(정확히 분류된 이미지의 비율)만 고려.

network.compile(optimizer='rmsprop',
                loss='categorical_crossentropy',
                metrics=['accuracy'])

train_images = train_images.reshape((60000, 28 * 28))
train_images = train_images.astype('float32') / 255

test_images = test_images.reshape((10000, 28 * 28))
test_images = test_images.astype('float32') / 255

from keras.utils import to_categorical 

train_labels = to_categorical(train_labels) 
test_labels = to_categorical(test_labels)




