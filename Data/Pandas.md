# Pandas
- 구조화된 데이터를 효과적으로 처리하고 저장
- Array 계산에 특화된 NumPy를 기반으로 설계

## Series
- numpy array가 보강된 형태로 Data와 Index를 가지고 있음
```python
import pandas as pd
#인덱스를 가지고 있고 인덱스로 접근 가능, name 인자로 데이터의 이름 지정 가능
data = pd.Series([1,2,3,4], index=['a', 'b', 'c', 'd'], name="Title") 
data['b']  # 2
```
