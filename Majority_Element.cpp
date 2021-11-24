//if an element appers in array more then n/2 times (when size of array is n)
//then the element is Majority element and I will print it.

//יש כמה דרכים לפתור את זה:
// אפשר למיין- ואז האיבר שהוא מייצג רוב נמצא באמצע
//אם יודעים את הטווח - נעשה באקט
// אחרת נעשה טבלת האש וכל הכנסה של מספר נבדוק אם הכמות שלו היא הרוב
//יש דרך עם הגדלת מונה והקטנה -בהתחלה מניחים שהאיבר הוא הראשון, ואז עבור כל מספר שחוזר על עצמו נגדיל מונה ועבור מס שונה - נקטין מונה- אם המונה הוא 0 נחליף את האיבר .

// הדרך האחרונה היא הכי יעילה אבל לא כל כך אינטואטיבית, אני אממש כאן את הטבלת האש

void main()
{
  int arr[] = {2,4,2,7,2,11,4,2,2}; // majority = 2
  int size = sizeof(arr)/sizeof(*arr);
  
  int major_val= majority(arr, size);
}

int majority(int *arr, int size)
{
  multiset<int> m;
  int limit = size/2;
  
  for(int i=0; i<size; i++)
  {
    m.insert(arr[i]);
    if(m.count(arr[i])>limit)
    {
      return arr[i];
    }
  }
  return -1;
}

