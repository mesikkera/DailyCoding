import pandas as pd
import numpy as np 
import matplotlib.pyplot as plt
import warnings
warnings.filterwarnings('ignore')

# dataset = pd.read_csv("/Users/nipun/Downloads/ml-100k/u.data",sep='\t',names="user_id,item_id,rating,timestamp".split(","))
# dataset.head()

from surprise import SVD
from surprise import Dataset 
from surprise.model_selection import cross_validate

data = Dataset.load_builtin('ml-100k')

algo = SVD() 

cross_validate(algo, data, measures=['RMSE', 'MAE'], cv=5, verbose=True) 