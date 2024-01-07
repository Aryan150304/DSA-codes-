// link coding ninjas - https://www.codingninjas.com/studio/problems/subsequences-of-string_985087?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_16&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h> 

void Solution(string str, string ans, vector<string> &finalans, int index){
	if(index>=str.size()){
		if(ans.length()==0){
			return ;
		}
		finalans.push_back(ans);
		return ;
	}
	Solution(str,ans,finalans,index+1);
	ans.push_back(str[index]);
	Solution(str,ans,finalans,index+1);

}
vector<string> subsequences(string str){
	string ans ="";
	vector<string>finalans;
	int index = 0;
	Solution(str,ans,finalans,index);
	return finalans;	
}
