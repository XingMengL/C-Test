//范围for循环
int main()
{
	int array[] = {1,2,3,4,5};
	/*for(int i = 0; i < 5; i++)
		array[i] = array[i] * 2;

	for (int* p = array; p < array + sizeof(array)/ sizeof(array[0]); ++p)     
		  cout << *p << endl; */
	for(auto& e: array )
		e *= 2;
	for(auto e:array)
		cout<<e<<endl;
	//for循环后的括号由冒号“ ：”分为两部分：第一部分是范围内用于迭代的变量， 第二部分则表示被迭代的范围。
 

	system("pause");
	return 0;
}
