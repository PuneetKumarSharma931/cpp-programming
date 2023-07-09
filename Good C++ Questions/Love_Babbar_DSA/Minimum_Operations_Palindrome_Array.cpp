
#include<iostream>
#include<vector>

using namespace std;

int findMin(vector<int> &nums)
	{
		int ans = 0;
		
		if(nums.size()==1)
			return 0;
			
		int suml = 0;
		int sumr = 0;
		int left = 0;
		int right = nums.size()-1;
		
		while(left<right) {
			
			if(suml==0 && sumr==0) {
				
				if(nums[left]==nums[right]) {
					
					left++;
					right--;
				}
				else {
					
					if(nums[left]<nums[right] && left<right-1) {
						
						suml = nums[left] + nums[left+1];
						left++;
						ans++;
					}
					else {
						
						if(right>left+1) {
							
							sumr = nums[right] + nums[right-1];
							right--;
							ans++;
						}
						else {
							
							break;
						}
					}
				}
			}
			else if(suml!=0 && sumr==0) {
				
				if(suml==nums[right]) {
					
					suml = 0;
					left++;
					right--;
				}
				else {
					
					if(suml<nums[right] && left<right-1) {
						
						suml = suml + nums[left+1];
						left++;
						ans++;
					}
					else {
						
						if(!(right>left+1))
							break;
							
						sumr = nums[right] + nums[right-1];
						right--;
						ans++;
					}
				}
			}
			else if(sumr!=0 && suml==0) {
				
				if(sumr==nums[left]) {
					
					sumr = 0;
					left++;
					right--;
				}
				else {
					
					if(sumr<nums[left] && left<right-1) {
						
						sumr = sumr + nums[right-1];
						right--;
						ans++;
					}
					else {
						
						if(!(right>left+1))
							break;
							
						suml = nums[left] + nums[left+1];
						left++;
						ans++;
					}
				}
			}
			else {
				
				if(suml==sumr) {
					
					suml = 0;
					sumr = 0;
					left++;
					right--;
				}
				else if(suml<sumr && left<right-1) {
					
					suml = suml + nums[left+1];
					left++;
					ans++;
				}
				else {
					
					if(!(right>left+1))
						break;
						
					sumr = sumr + nums[right-1];
					right--;
					ans++;
				}
			}
		}
		
		if(left>right) {
			
			return ans;
		}
		
		if(left==right)
			return ans;
		
		
		if(suml==0 && sumr==0) {
				
			if(nums[left]==nums[right]) {
				
				return ans;
			}
			else {
				
				return ans+1;
			}
		}
		else if(suml==0 && sumr!=0) {
			
			if(sumr==nums[left]) {
				
				return ans;
			}
			else {
				
				return ans+1;
			}
		}
		else if(suml!=0 && sumr==0) {
			
			if(suml==nums[right]) {
				
				return ans;
			}
			else {
				
				return ans+1;
			}
		}
		else {
			
			if(suml==sumr)
				return ans;
			return ans+1;
		}
		
		return ans;
		
	}

int main() {

    system("clear");

    vector<int> arr;

    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(9);
    arr.push_back(1);


    cout<<findMin(arr);

    return 0;
}