import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.datasets import load_iris
iris = load_iris()
x, y = iris.data, iris.target
x_train, x_test, y_train, y_test = train_test_split(
    x, y, test_size=0.2)
knn = KNeighborsClassifier(n_neighbors=5)
knn.fit(x_train, y_train)
print("Response for test dataset:")
y_pred = knn.predict(x_test)
print(y_pred)

'''

    "0": setosa
    "1": versicolor
    "2": virginica
'''
