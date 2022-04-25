# import numpy as np
# np_Arr = np.array([1,2,3,4,5],dtype="uint8")
# print(type(np_Arr))
# print(np_Arr.ndim)


# import numpy as np
# print(np.arange(5))
# a = np.random.permutation(np.arange(10))
# b = np.random.permutation(np.arange(10))
# c = np.concatenate([a,b])
# print(c)

# import numpy as np
# a = np.random.permutation(np.arange(5))
# print(a)

import numpy as np
# a = np.arange(5)
# # print(a)
# print(np.concatenate([np.random.permutation(np.arange(5)),np.random.permutation(np.arange(5))]))

# a = np.arange(10).reshape(2,5)
# b = np.arange(10).reshape(2,5)
# print(np.vstack([a,b]))


a = np.arange(10).reshape(2,5)
b = np.arange(10).reshape(2,5)
# print(a)
# print(b)
# print(np.concatenate([a,b],axis = 0))
# print(np.vstack([a,b]))
# print(np.hstack([a,b]))
# print(np.concatenate([a,b],axis=0))

# print(np.array([1,2,3,4,5]))
arr = np.array([1,2,3,4,5])
arr = np.append(arr,8)
print(arr)