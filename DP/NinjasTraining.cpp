TC : O(n*4*3)
SC :O(n) + O(n*4);


int f(int day , int last , vector<vector<int>> &points) {
    //base case
    if(day == 0 ) {
        int maxi = 0;
        for(int task = 0 ; task < 3 ; task++) {
            if(task != last){
                 maxi = max(maxi , points[day][task]);
            }
        }
        return maxi;   
    }
    
    int maxi = 0;
    for(int task = 0 ; task < 3 ; task++ ) {
        if(task != last ) {
            //upgrade the points
            int point = points[day][task] + f(day-1 , task , points);
            maxi = max(maxi , point);
        }
        
    }
    return maxi;
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    //creating a function
    return f(n-1 ,3  , points);
}
------------
    TABULATION
--------------
SPACE OPTIMIZATION

TC : O(n*4*3)
SC :O(n);

int f(int day , int last ,  vector<vector<int>> &points ,vector<vector<int>> &dp){
    if(day == 0 ) {
        int maxi = 0;
        for(int task = 0 ; task < 3 ; task ++) {
            if(task != last) {
                maxi = max(maxi , points[day][task]);
          
            }
        }
        return maxi;
    }
    
    if(dp[day][last] != -1) return dp[day][last];
    //else statement;
    int maxi = 0;
    for(int task = 0 ; task < 3 ; task++) {
        if(task != last) {
           int point = points[day][task] + f(day-1, task , points , dp) ;
            maxi = max(maxi , point);
        }
    }
    return dp[day][last] =  maxi;
    
} 


int ninjaTraining(int n, vector<vector<int>> &points)
{
      vector<int> prev(4,0);
    
    prev[0] = max(points[0][1] , points[0][2]);
    prev[1] = max(points[0][0] , points[0][2]);
    prev[2] = max(points[0][0] , points[0][1]);
    prev[3] = max(points[0][1] , max(points[0][1] , points[0][2]));
    
    //do for loop for day and the last element
    
    for(int day = 1; day<n ; day++) {
        //create temp varaiable which dtores the array of previous
       vector<int> temp(4,0 );
        for(int last = 0 ; last < 4 ; last ++) {
            temp[last] = 0;
            // do recursion here
            
            for(int task = 0 ; task < 3 ; task++) {
                //find the max
                if(task != last) {
                  temp[last] = max(temp[last] , points[day][task] + prev[task]);
                }
                
            }
        }
        prev = temp;
    }
    return prev[3];
}
