void sortStack(stack<int> &stack)
{
	// Write your code here
    vector<int>ele;
    while(!stack.empty()){
        ele.push_back(stack.top());
        stack.pop();
    }
    sort(ele.begin(), ele.end());
    for(int i = 0; i < ele.size(); i++){
        stack.push(ele[i]);
    }
    
}