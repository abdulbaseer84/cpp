import java.util.*;

// public class largestnumberinarray{
//     public static void main(String[] args){
//         int arr[]= {3,5,6,7,8,6};
//         int n=6;
//         int largest=arr[0];
//         for(int i=1;i<n;i++){
//             if(arr[i]>largest){
//                 largest=arr[i];
//             }
//         }
//         System.out.println("The largest number in the array is: " + largest);
//     }
// }

public class largestnumberinarray{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements in the array: ");
        int n = sc.nextInt();
        int arr[] = new int[n];         
        System.out.println("Enter the elements of the array:");
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }   
        int largest = arr[0];
        for(int i=1; i<n; i++){
            if(arr[i] > largest){
                largest = arr[i];
            }
        }
        System.out.println("The largest number in the array is: " + largest);
    }
}