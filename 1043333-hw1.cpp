#include <iostream>
#include <vector>

using namespace std;
void find(vector<bool>&road, vector<int>&tmp, vector<int>&ans, int n,int point,int CTpoint);

int main() {
	vector<bool>road;
	vector<int>tmp;
	vector<int>ans;
	int n,size,i=1;
	bool in;
	cout << "enter number of city\n";
	cin >> n;
	cout << "enter the road\n";
	cout << "0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 ";
	
	//input
	cout << "city 1"  << endl;
	cin >> in;
	do
	{
		road.push_back(in);
		size = road.size();
		
		if (i == size/n) {
			i++;
			if (i >  n)break;
			cout << "city " << i << endl;
		}		
	} while (cin>>in);

	//找答案
	for (int a = 0; a < n; a++) {
		find(road, tmp, ans, n, a*n, n);
		cout << "city: " << a << "finished\n";
	}
	cout << "start to analysize\n";
	/*vector<int>::iterator a = ans.begin();
	cout << *(a+1) << endl;
	cout << &a << endl;*/
	/*for (vector<int>::iterator a = ans.begin(); a < ans.end() - n; *a=*a + n) {
		if (*a/n != *(a + n - 1)/n) {
			ans.erase(a, a + n - 1);
		}
		for (vector<int>::iterator x = a; x < x+n; x++) {
			for (vector<int>::iterator y = a; y < y + n; y++) {
				if (*x == *y) {
					ans.erase(a, a + n - 1);
				}
			}
		}
	}*/
	for (int a = 0; a <= ans.size() - n; a += n) {
		//if (ans[a] / n != ans[(a + n - 1)] / n|| ans[a] % n != ans[(a + n - 1)] % n) {
		if ((ans[a] / n)+1 != (ans[(a + n - 1)] % n)+1 || ans[a] / n == ans[(a + n - 1)] / n|| ans[a] % n == ans[(a + n - 1)] % n) {
			ans.erase(ans.begin() + a, ans.begin() + (a + n));
			a -= n;
		}
	}
	for (int a = 0; (ans.size() != 0) && a <= ans.size() - n; a += n) {
		bool flag = false;
		for (int x = a; (ans.size() != 0) && x < a+n; x++) {
			for (int y = a + n - 1; (ans.size() != 0) && y > x; y--) {
				if ( (ans.size() != 0) && (ans[x] / n == ans[y] / n || ans[x] % n == ans[y] % n) ) {
					ans.erase(ans.begin() + a, ans.begin() + (a + n));
					flag = true;
					break;
				}
			}
			if (flag) {				
				a -= n;
				break;
			}
		}
	}
	if (ans.size() > 0) {
		cout << "Total have " << ans.size() / n << " Hamilton Cycle\n";
		for (int k = 0; k < ans.size(); k++) {
			if (k % n == 0) {
				cout << "\n\n" << ans[k] / n + 1;
				continue;
			}
			if (k % n == n - 1) {
				cout << "--->" << ans[k] / n + 1 << "--->" << ans[k] % n + 1;
				continue;
			}
			cout << "--->" << ans[k] / n + 1;
		}
	}
	else {
		cout << "There are no Hamilton Cycle";
	}
	cout << endl<<endl;
	::system("pause");
}

void find(vector<bool>&road, vector<int>&tmp, vector<int>&ans, int n, int point, int CTpoint) {

	bool flag = true;
	vector<int> canroad;
	while (true) {
		//如果找到最後一層
		if (CTpoint == 0) {
			ans.insert(ans.end(), tmp.begin(), tmp.end());
			//tmp.pop_back();
			break;
		}
		/*if (CTpoint != n) {
			bool report = false;
			int i = tmp.size() - 1;
			for (; i > tmp.size() - (n-CTpoint); i--)
			{
				if (tmp[i]%n == point%n) {
					report = true;
					break;
				}
			}
			if (report)
			{
				break;
			}
		}*/
		/*//找到最後一個
		if (point == n*n && CTpoint == n) {
			break;
		}
		//如果城市路徑為F
		while (road[point] == false) {
			point++;
		}
		*/

		//如果路徑是T
		/*if (road[point]) {
			tmp.push_back(point);
			::find(road, tmp, ans, n, (point % n )*n,CTpoint-1);
			if (point%n != n - 1) {
				point++;
				//continue;
				/*tmp.pop_back();
				break;
			}
			
		}*/
		//列出所有可能性
		int number=0;
		for (int i = (point/n)*n; i < n+ (point/n)*n ; i++) {
			if (road[i] == true) {
				number++;
				canroad.push_back(i);
			}
		}
		/*int npoint = point;
		while (road[point]&&number>0) {
			tmp.push_back(npoint);
			::find(road, tmp, ans, n, (point % n)*n, CTpoint - 1);
			number --;
			npoint++;
			if (npoint > n)break;
			while (road[npoint] == false&&npoint<n) {
				npoint++;
			}
		}*/
		//爬路徑
		for (int i = 0; i < number;i++ ) {
			tmp.push_back(canroad[i]);
			::find(road, tmp, ans, n, (canroad[i] % n)*n, CTpoint - 1);
			tmp.pop_back();
		}
		
		break;
			/*if (point%n != n - 1) {
				point++;
			}	*/	
		//如果找到最後
		/*if (point%n == n - 1&&CTpoint!=n) {
			if (flag == false) {
				tmp.pop_back();
				break;
			}
			if (road[point] != false) {
				flag = false;
				continue;				
			}
			tmp.pop_back();
			break;
		}
		if (point%n == n - 1 && CTpoint == n) {
			point++;
			continue;
		}*/
		
	}
}