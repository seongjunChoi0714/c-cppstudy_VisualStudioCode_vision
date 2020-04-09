
Selection Sort Code(선택 코드 정렬)
처음값과 최소값을 찾아 봐꾸면서 저장하는 코드
//count=비교한 횟수
void selectionsort (int list[], int last, long &count)
{
	
	for (int current = 0; current < last; current++)
	{
		int  smallest = current;
	
		for(int walker = current+1 ; walker <=last ; walker++)
			if(list[walker] < list[smallest])
			{smallest = walker;}
	
		int temp = list[current];
		list[current] = list[smallest];
		list[smallest] = temp;
		count++;
	}

}

-----------------------------------------------------------------------------

Bubble Sort Code(버블 정렬 코드)
최소값이 바로 앞의 값과 비교되면서 점점 올라오는 코드
//count=비교한 횟수
void bubblesort (int list[],int last, long &count)
{
	
	for(int current = 0;current <last;current++)
	{
		for (int walker = last; walker > current; walker--)
		{
			if(list[walker] < list[walker-1])
			{
			int temp = list [walker];
			list [walker] = list [walker-1];
			list [walker-1] = temp;
			count++;
			}
		}
	}


}

-----------------------------------------------------------------------------

Insertion Sort Code(삽입 정렬 코드)
배열이 차례대로 앞에서 저장되며 다음부분의 값이 적절한 위치에 들어가는 코드

void insertionSort(int list[],int last)
{
	for(int current = 1; current <= last; current++)
		insertOne(list,current,last);
	return;
}
void insertOne(int list[], int current, int last)
{
	bool located = false;
	int temp = list[current];
	int walker;
	for(walker = current - 1;walker>=0 && !located;)
	{
		if(temp<list[walker])
		{
			list[walker+1] = list[walker];
			walker--;
		}
		else
			located = true;
	}
	list[walker+1] =temp;
	return;
}

-------------------------------------------------------------------------------

Sequential Search Code
순차 검색 코드
//locn=비교한 횟수
bool seqSearch(int list[],int last,int target, int& locn)
{
	int looker = 0;
	while(looker<last && target != list[looker])
		looker++;
	locn = looker;
	return(target==list[looker]);
}

---------------------------------------------------------------------------------

Binary Search Code(이진 검색 코드)

bool binarySearch(int list[],int end,int target, int& locn)
{
	int first = 0;
	int last = end;
	int mid;
	while (first<=last)
	{
		mid=(first+last)/2;
		if(target>list[mid])
			first = mid +1;
		else if(target < list[mid])
			last=mid -1;
		else
			first = last + 1;
		
	}
	locn = mid;
	return target == list[mid];
}