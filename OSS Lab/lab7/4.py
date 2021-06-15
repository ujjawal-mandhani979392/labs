import pandas as pd
data = pd.read_csv("data.csv")


def count_cars():
    print("\ncount cars per company")
    t = data.company.value_counts()
    print(t)


count_cars()
