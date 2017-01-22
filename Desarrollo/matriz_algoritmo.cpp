#include <iostream>
#include <vector>

int main(){
	std::vector<int> s;
	for (int m=0; m<27; m++) {
		s.push_back(m+1);
	}
	
	int w=3, h=3, z=3, w1 = w, h1 = h;
	
	for (int i = 0; i < z; i++) {
		
		for (int j = h*i; j < h1; j++) {
			printf("i:%d j:%d k: ",i+1,j+1);
		
			for (int k = w1-w; k < w1; k++) {
				if(k < s.size())
					printf("%d ", s.at(k));
			}
			
			w1 += w;
			printf("\n");
			
		}
		
		h1 = h + h*(i+1);
		w1 = w + w*h*(i+1);
		printf("______\n");
	}
	
	return 0;
}
