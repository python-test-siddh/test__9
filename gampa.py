import moku
for _a in dir(moku):
	print(_a)
print(moku)
print(moku.moku)

_st='y'
_arr=bytes(_st,'utf-8')
print(moku.moku(_arr))

