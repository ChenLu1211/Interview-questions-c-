//given an array ->
//every position means how many jumps we can do to the next indexes
//we need to return if we can get the last index (true\false)

//for example: [2, 3, 1, 1, 4] -> true  (1 jump and then 3 jumps)  | [3, 2, 1, 0, 4] -> false

//הרעיון לפתרון יעיל:
//נלך מסוף המערך לתחילתו, וכל פעם נסמך האם המיקום שאנחנו עליו הוא מיקום טוב
// מיקום טוב נקרא כך אם מהמיקום  עצמו ועוד הערך שבתוך המיקום מצליחים להגיע למיקום טוב האחרון שנשמר
// לדוגמא [2,3,1,1,4] אורך המערך הוא 5  המיקום הטוב מוגדר כאורך המערך פחות 1 
//כלומר האינדקס האחרון במערך שבדוגמא זו הוא 4.
// ונתחיל לולאה מאינדקס אחד לפניו כלומר מאינדקס 3
// ונבדוק האם שלוש ועוד הערך שבתוכו שזה 1 גדול שווה לאינדקס 4 ,
//התשובה כן ולכן נגדיר את אינדקס 3 כמיקום טוב חדש וכך הלאה
//כשנסיים נבדוק אם 0 הוא מיקום טוב אם כן נחזיר אמת אחרת שקר



void main()
{
  int arr[] = {2, 3, 1, 1, 4};
  bool jump = canJump(arr);
}

bool canJump(int* arr)
{
  int size= sizeof(arr)/sizeof(*arr);
  int goodIndex = size-1;
  
  for(int i=size-2; i>=0 ; i--)
  {
    if(arr[i]+i >= goodIndex)
    {
      goodIndex = i;
    }
  }
  
  if(goodindex == 0)
  {
    return true;
  }
  return false;
}
