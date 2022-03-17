

// // Approach: Using brute force

// // Assuming all the elements in the matrix are non-negative. Traverse through the matrix and if you find
// //  an element with value 0, then change all the elements in its row and column to -1, 
// //  except when an element is 0. The reason for not changing other elements to 0, but -1, 
// //  is because that might affect other columns and rows. Now traverse through the matrix 
// //  again and if an element is -1 change it to 0, which will be the answer.



// // Time Complexity:O((N*M)*(N + M)). O(N*M) for traversing through each element and (N+M)for traversing to row and column of elements having value 0.

// // Space Complexity:O(1)



// #include<bits/stdc++.h>
// using namespace std;



// void set_zero(vector<vector<int>>&matrix)
// {
   
//     int row=matrix.size();
//     int col=matrix[0].size();

//     for(int i=0;i<row;i++)
//     {
//         for(int j=0;j<col;j++)
//         {
//             if(matrix[i][j]==0)
//             {
//                 int ind=i-1;

//                 while(ind >= 0)
//                 {
//                     if(matrix[ind][j]!=0)
//                     {
//                         matrix[ind][j]=-1;
//                     }
//                     ind--;
//                 }

//                 ind=i+1;
//                  while(ind <row)
//                 {
//                     if(matrix[ind][j]!=0)
//                     {
//                         matrix[ind][j]=-1;
//                     }
//                     ind++;
//                 }

//                 ind=j-1;

//                 while(ind >= 0)
//                 {
//                     if(matrix[i][ind]!=0)
//                     {
//                         matrix[i][ind]=-1;
//                     }
//                     ind--;
//                 }

//                 ind=j+1;
//                  while(ind <col)
//                 {
//                     if(matrix[i][ind]!=0)
//                     {
//                         matrix[i][ind]=-1;
//                     }
//                     ind++;
//                 }

//             }
//         }
//     }

//     for(int i=0;i<row;i++)
//     {
//         for(int j=0;j<col;j++)
//         {
//             if(matrix[i][j]<=-0)
//             {
//                 matrix[i][j]=0;
//             }
//         }
//     }

// }

// int main()
// {
//     vector<vector<int>>arr;
//     arr={{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

//     set_zero(arr);

//     for(int i=0;i<arr.size();i++)
//     {
//         for(int j=0;j<arr[0].size();j++)
//         {
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<"\n";
//     }




// }











// Solution 2:Better approach

// Intuition: Instead of traversing through each row and column, we can use dummy arrays 
// to check if the particular row or column has an element 0 or not, which 
// will improve the time complexity.

// Approach:Take two dummy array one of size of row and other of size of column.Now
//  traverse through the array.If matrix[i][j]==0 then set dummy1[i]=0(for row) and 
//  dummy2[j]=0(for column).Now traverse through the array again and 
//  if dummy1[i]==0  || dummy2[j]==0 then arr[i][j]=0,else continue.

// Time Complexity: O(N*M + N*M)

// Space Complexity: O(N)



// #include<bits/stdc++.h>
// using namespace std;

// void set_zero(vector<vector<int>>&matrix)
// {
   
//     int row=matrix.size();
//     int col=matrix[0].size();

//     vector<int>arr1(row,-1);
//     vector<int>arr2(col,-1);

//     for(int i=0;i<row;i++)
//     {
//         for(int j=0;j<col;j++)
//         {
//             if(matrix[i][j]==0)
//             {
//                 arr1[i]=0;
//                 arr2[j]=0;

//             }
//         }
//     }
//      for(int i=0;i<row;i++)
//     {
//         for(int j=0;j<col;j++)
//         {
//             if(arr1[i]==0 or arr2[j]==0)
//             {
//                 matrix[i][j]=0;

//             }
//         }
//     }

    

// }

// int main()
// {
//     vector<vector<int>>arr;
//     arr={{1,1,1}, {1,0,1}, {1,1,1}};

//     set_zero(arr);

//     for(int i=0;i<arr.size();i++)
//     {
//         for(int j=0;j<arr[0].size();j++)
//         {
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<"\n";
//     }




// }








// ###Optimizing the better approach.

// Intuition: Instead of taking two dummy arrays we can use the first row and column of
//  the matrix for the same work. This will help to reduce the space complexity of the 
//  problem. While traversing for the second time the first row and column will be computed
//   first, which will affect the values of further elements that’s why we traversing in the 
//   reverse direction.

// Approach:Instead of taking two separate dummy array,take first row and column
//  of the matrix as the array for checking whether the particular column or row 
//  has the value 0 or not.Since matrix[0][0] are overlapping.Therefore take separate 
//  variable col0(say) to check if the 0th column has 0 or not and use matrix[0][0] to 
//  check if the 0th row has 0 or not.Now traverse from last element to the first element 
//  and check if matrix[i][0]==0 || matrix[0][j]==0 and if true set matrix[i][j]=0,else continue.



//  Time Complexity: O(2*(N*M)), as we are traversing two times in a matrix,

// Space Complexity: O(1).





#include<bits/stdc++.h>
using namespace std;


void set_zero(vector<vector<int>>& matrix) {
        
        
    int row=matrix.size();
    int col=matrix[0].size();

    int col0=1;

    for(int i=0;i<row;i++)
    {
        if(matrix[i][0]==0)
        {
            col0=0;
        }
        for(int j=1;j<col;j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[0][j]=matrix[i][0]=0;

            }
        }
    }
     for(int i=row-1;i>=0;i--)
    {
        for(int j=col-1;j>=1;j--)
        {
            if(matrix[i][0]==0 or matrix[0][j]==0)
            {
                matrix[i][j]=0;

            }
        }
         
         if(col0==0)
             matrix[i][0]=0;
    }

    }


int main()
{
    vector<vector<int>>arr;
    arr={{1,1,1}, {1,0,1}, {1,1,1}};

    set_zero(arr);

    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }



}