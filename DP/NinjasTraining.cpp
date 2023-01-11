
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
