import numpy as npi
import matplotlib.pyplot as plt
import pandas as pd
df = pd.DataFrame({"Method": ['A', 'B', 'C', 'D'], "Result1": [
                  2, 5, 8, 5], "Result2": [3, 2, 5, 7]})
df.plot(x="Method", y=["Result1", "Result2"], kind="bar")
plt.show()
