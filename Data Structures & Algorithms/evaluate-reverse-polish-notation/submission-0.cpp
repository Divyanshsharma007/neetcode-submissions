class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>stack;

        for(string& c : tokens){
            if(c =="+"){
                int a =stack.top(); stack.pop();
                int b =stack.top(); stack.pop();
                stack.push(b+a);
            }
            else if(c =="-")
            {
                int a = stack.top() ; stack.pop();
                int b = stack.top() ; stack.pop();
                stack.push(b-a);                
            }
            else if(c =="/"){
                int a = stack.top() ; stack.pop();
                int b = stack.top() ; stack.pop();
                stack.push(b/a);                 
            }
            else if(c=="*"){
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(a*b);
            }
            else{
               stack.push(stoi(c)); 
            }
        }
        return stack.top();
    }
};
