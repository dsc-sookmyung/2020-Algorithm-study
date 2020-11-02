#include <iostream>
#include <string>
using namespace std;

class stack{
	private:
	int nums[10001];
	int idx=0;
	int stack_size=0;
	
	public:
	void push(int x){
		nums[idx]=x;
		idx++;
		stack_size++;
	}
	void pop(){
		if(stack_size!=0){
			printf("%d\n",nums[idx-1]);
			nums[idx]=0;
			idx--;
			stack_size--;
		}else{
			printf("-1\n");
		}
	}
	void size(){
		printf("%d\n",stack_size);
	}
	void empty(){
		if(stack_size!=0)
			printf("0\n");
		else
			printf("1\n");
	}
	void top(){
		if(stack_size!=0)
			printf("%d\n",nums[idx-1]);
		else
			printf("-1\n");
	}
};

int main(){
	stack s;
	int n;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		string str;
		string op[5]={"push","pop","size","empty","top"};
		
		cin>>str;
		int x;
		if(str=="push"){
			scanf("%d",&x);
		}
		
		for(int i=0;i<5;i++){
			if(str==op[i]){
				switch(i){
			case 0:
			s.push(x);
			break;
			case 1:
			s.pop();
			break;
			case 2:
			s.size();
			break;
			case 3:
			s.empty();
			break;
			case 4:
			s.top();
			break;
		}
			}
		}
		
		
	}
}