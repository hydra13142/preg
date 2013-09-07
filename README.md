preg
====
a DFA regex implementation made of C

C语言实现的DFA正则表达式，作为一个DFA，没有分组和分组提取

当然，更不会有分组的命名、前后向预查

支持\t、\r、\n、\v、\f五个转义字符，以及\x加hex数的转义字符

预设字符集，只支持\s、\d、\c、\w，不能使用[::]类型的字符集

对char*类型进行的匹配，应保证提供的规则字符串和目标字符串编码一致

内部使用字位来实现的集合，邻接表表示的DFA

边界的实现限定为开始的^和末尾的$，字符串内部的不被识别为边界字符；

可以用'\'转义起始和末尾的这两个字符

类型

	regex 内部实现不需在意，基本上我们使用指针
	
	group 包含两个成员，pos和len，都是long类型

函数

	regex *preg_make(char*)
	使用字符串生成一个regex指针

	long preg_more(const regex*,char*)
	寻找最长的匹配（匹配起始位置固定为起点），返回匹配长度，如果为0则表示匹配失败

	long preg_less(const regex*,char*)
	寻找最短的匹配（匹配起始位置固定为起点），返回匹配长度，如果为0则表示匹配失败

	group preg_find(const regex*,char*)
	返回值的pos表示第一个能实现匹配的位置，pos<0这表示没有找到；len表示匹配的长度

	void preg_free(regex*)
	释放regex指针

额外

	额外提供的preg_show函数可以用于显示regex内部DFA的结构，帮助学习regex：
	
	void preg_show(const regex *reg,long type)
	
	会输出DFA的具体构造，包括字符分组、状态转移表、出口等；
	
		type==0 时不显示字符分组；
		
		type >0 时只显示使用字符的分组；
		
		type <0 时显示全部字符的分组；
