//  Leetcode Link :: https://leetcode.com/problems/design-a-food-rating-system/
// Date => 17/12/2023


//Using maps/set as requirement
/*T.C -
FoodRatings - O(n)
changeRating - log(n) due to erase function used in ordered_set
highestRated - O(1)
S.C - O(n) in all maps
*/
class FoodRatings {
public:

//  lets decide the data structure which we will nedd for each operation


//  first lets see => changeRating(food,newRating)
// as we need to change rating of specific food
// so we should have a mapping between food and rating
// so here we need map to store mapping between [food->rating] (unordered_map<string,int>)
unordered_map<string,int> food_rating;
 

// now highestRated(cuisine)
// we need food with highest priority of particular cuisine so we should store
//  cuisine -> {{r1,food1},{r2,food2}}
// we need map<string,pair<string,int>> 
// also we need to get food with highest rating so we can use set to store the pair
// map<string,set<pair<string,int>>>  
// and first element in pair will be rating[since we needed hoghest rated food]
// and if rating ties we need to take lexiographically smaller food
unordered_map<string,set<pair<int,string>>> cuisine_rating_food;


// also when we change foodrating() we need to update it in other map as well
// so we need to know food belong to which cuisine
// so map<string,string> to store {food->cuisine}

unordered_map<string,string> food_cuisine;


// corner case for highestRating(cuisine) when there is tie in rating
// E.g Indian => {{15,abc},{16,shi},{16,xyz}} => since set store in ascending order
// now we will return last elemnt of this cuisine {16,xyz} which is wrong as there is a tie
// so we will store rating as -(rating)
// Indian => {{-16,shi},{-16,xyz},{-15,abc}}
// now we can written first elemnt blindly if there is a tie automatically 
// lexiograohical smallest food is returned





    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) 
    {
        int n=foods.size();
        // O(N)
        for(int i=0;i<n;i++)
        {
            string food=foods[i];
            string cuisine=cuisines[i];
            int rating=ratings[i];

            food_cuisine[food]=cuisine;
            food_rating[food]=rating;
            cuisine_rating_food[cuisine].insert({-rating,food});
        }
    }
    
    void changeRating(string food, int newRating) 
    {
        string cuisine=food_cuisine[food];
        int oldrating=food_rating[food];

        // update the new rating in food_rating
        food_rating[food]=newRating;

        // now update in other maps
        // first erase the old entries
        cuisine_rating_food[cuisine].erase({-oldrating,food}); // O(log(size of set))
        // add the new entry 
        cuisine_rating_food[cuisine].insert({-newRating,food}); // O(log(size of set))


    }
    
    string highestRated(string cuisine) 
    {
        return begin(cuisine_rating_food[cuisine])->second; // O(1)
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */