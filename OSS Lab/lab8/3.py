from sklearn.model_selection import train_test_split
from sklearn.datasets import load_iris
iris = load_iris()
x, y = iris.data, iris.target
x_train, x_test, y_train, y_test = train_test_split(
    x, y, test_size=0.3, random_state=123)
print("\n70% train data:")
print(x_train)
print(y_train)
print("\n30% test data:")
print(x_test)
print(y_test)
