// reversing a string using recursion 
#include<iostream>
#include<string>
using namespace std ;

void reverse(string &str, int size , int i, int j){
    if(i>=j){
        return ;
    }
    swap(str[i],str[j]);
    i++;
    j--;
     reverse(str,size,i,j);
}


int main(){
    string str;
    int len;
    cout<<"Enter the string to be reversed"<<endl;
    cin>>str;
    int i =0;
    int j = str.length()-1;
    reverse(str,str.length(),i,j);
    cout<<str<<endl;
    return 0;
}


/// adding coding ninjas solution too
#include <bits/stdc++.h> 

void reverse(string &str, int i , int j){
    if(i>=j){
        return ;
    }
    swap(str[i],str[j]);
    i++;
    j--;
    reverse(str,i,j);
}


string reverseString(string str)
{
	int i =0;
	int j = str.length()-1;
	reverse(str,i,j);
	return str;
	
}
