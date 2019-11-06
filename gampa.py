import moku
for _a in dir(moku):
	print(_a)
print(moku)
print(moku.moku)

_st='yellow'
_arr=bytes(_st,'utf-8')
for _a in _arr:
	print(moku.moku(_arr[_a]))
	print(type(moku.moku(_arr[_a])))
	print(len(moku.moku(_arr[_a])))

