# XGBDTI: An XGBoost Ensemble Approach for Network-Based Drug-Target Interaction Prediction
XGBDTI is a computational pipeline to predict novel drug-target interactions (DTIs) from heterogeneous network.

## Requirements
The dependent packages are as following. They are easy to download using `pip` except xgboost。
* xgboost (You can download & install this package following(https://blog.csdn.net/mmc2015/article/details/44623301))
* numpy 
* sklearn 
* pandas
* scipy
* matplotlib

## Quick Start
You can just run <code>python2 main.py</code> to reproduce the cross validation results of XGBDTI. Options are:
- `-r`: negtive positive ratio, one or ten

## Tutorial
Of course, you can go through all the process by run <code>python2 totalPipeline.py</code> Options are:
- `-d`: drug network list, seperated by comma, without suffix.
- `-p`: protein network list, seperated by comma, without suffix.
- `-dm`: drug feature vector dimensions
- `-pm`: protein feature vector dimensions
- `-r`: negtive positive ratio
As for more hyperparameters in XGBoost model, you can modify them in the `src/model.py`

## Code & Data
### `src/` directory
```
.
├── main.py
├── utils.py
├── totalPipeline.py
└── tuning_xgboost.py
```
- `utils.py`: Contain all the important methods and functions in this project
- `main.py`: XGBDTI quick start
- `tuning_xgboost.py`: Greedy grid search for XGBoost hyperparameters
- `totalPipeline.py`: Go through all the process for XGBDTI

### `Data/` directory
```
../Data/
├── InteractionData
│   ├── disease.txt
│   ├── drug.txt
│   ├── mat_drug_disease.txt
│   ├── mat_drug_drug.txt
│   ├── mat_drug_se.txt
│   ├── mat_protein_disease.txt
│   ├── mat_protein_drug.txt
│   ├── mat_protein_protein.txt
│   ├── protein.txt
│   └── se.txt
├── SimilarityData
│   ├── Similarity_Matrix_Drugs.txt
│   └── Similarity_Matrix_Proteins.txt
├── drug_dict_map.txt
└── protein_dict_map.txt
```
### `DataSet/` directory
pre-trained data set. 
The integer denotes the ratio of negative to positive.
### `feature/` directory
pre-trained vector representations for drugs and proteins.
The integer denotes the dimension of the feature vectors.
### `DataSet` directory
Beforehand data set for XGBoost model.
### `network/` directory
pre-computed similarity matrices.
### `whole/` directory
This directory stores the data and program for test on the whole drug-target interaction network. And the drugs(or proteins) with no interaction was moved.
Due to time pressure, I did not add comments. So the script in this folder is a bit confusing.
### `supplement/` directory

