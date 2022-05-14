![pandemic_map](https://user-images.githubusercontent.com/66558110/168427986-8b8ba8a3-c661-45bd-acf4-336653b387af.jpg)
<div dir="rtl" lang="he">

# פאנדמיק - שלב ב

"כדי להתאמן בהתמודדות עם מגפות עולמיות, אנחנו צריכים משחקים"
[(ביל גייטס, 2015)](https://www.ted.com/talks/bill_gates_the_next_outbreak_we_re_not_ready#t-389693).
אחד המשחקים שנוצרו כדי להתאמן בהתמודדות עם מגפות הוא
[פאנדמיק](https://www.zmangames.com/en/products/pandemic/).
זהו משחק לוח ל-2 עד 4 שחקנים, המשחקים במשותף כדי לרפא מחלות ולגלות תרופות.

במטלה זו נממש חלק מחוקי המשחק, עבור שחקן אחד בלבד.

## הלוח
לוח המשחק הוא מפה של העולם, ובה 48 ערים.
חלק מהערים מחוברות בקו המאפשר לנסוע ביניהן.
ניתן לראות את רשימת הערים והקשרים ביניהן
[בתמונה זו](https://media.wnyc.org/i/1500/900/c/80/1/1537_Pandemic_main.jpg).
הערים מחולקות לארבעה צבעים - כחול, צהוב, שחור ואדום - 12 ערים מכל צבע.

רשימת הערים, הצבעים והקשרים נמצאת גם בקובץ
[cities_map.txt](cities_map.txt) - אפשר להשתמש בו לפי שיקול דעתכם (לא חובה).
הקובץ נשלח ע"י אוריה אלפרין - תודה רבה!


במטלה זו, הלוח מיוצג ע"י המחלקה 
`Board`.


## הקלפים
ישנם 48 קלפים - קלף אחד לכל עיר.

שמות הערים בקוד יהיו בדיוק כמו על המפה, בלי הרווחים. לדוגמה, השם של העיר ניו יורק הוא
`NewYork`.
יש להקפיד על האיות על-מנת למנוע שגיאות קומפילציה.


## המחלות
ישנן מחלות מארבעה צבעים - כחול, צהוב, שחור ואדום.
בכל עיר עשויות להיות "קוביות מחלה" בצבע המתאים לאותה עיר.

במחלקה "לוח" יש לממש את השיטות הבאות (ראו בקבצי הדוגמה):

* אופרטור סוגריים מרובעים [] - מקבל כפרמטר מזהה-עיר, ומאפשר לקרוא ולעדכן את רמת המחלה (=מספר קוביות המחלה) באותה עיר.
לדוגמה:
`board[City::HongKong] = 2`
מציבה שתי קוביות-מחלה אדומות בעיר הונג קונג.
* אופרטור פלט - מציג את מצב הלוח בפורמט כלשהו לבחירתכם. מצב הלוח כולל את:
   * רמת המחלה בכל אחת מהערים;
   * התרופות שהתגלו עד כה (ראו הסבר למטה);
   * תחנות-מחקר שנבנו עד כה (ראו הסבר למטה).
* `is_clean` - שיטה בוליאנית ללא פרמטרים,
המחזירה "אמת" אם ורק אם כל הלוח נקי - אין שום קוביות מחלה.
* `remove_cures` - שיטה ללא פרמטרים, המסירה מהלוח את כל התרופות שהתגלו עד כה (ראו הסבר למטה). שיטה זו נועדה לצורך כתיבת בדיקות; היא אף פעם לא זורקת חריגה, ואין צורך לבדוק אותה באופן מיוחד.
* `remove_stations` - שיטה ללא פרמטרים, המסירה מהלוח את כל תחנות המחקר שהתגלו עד כה (ראו הסבר למטה). שיטה זו נועדה לצורך כתיבת בדיקות; היא אף פעם לא זורקת חריגה, ואין צורך לבדוק אותה באופן מיוחד.

## השחקן
השחקן מתחיל את המשחק באחת הערים,
ומקבל מספר קלפים.
בכל תור, הוא יכול לבצע אחת מהפעולות הבאות (ראו בקבצי הדוגמה):

1. נסיעה - `drive` - מעבר מהעיר הנוכחית לעיר סמוכה (בהתאם למפת הקשרים).
1. טיסה ישירה - `fly_direct` - מעבר מהעיר הנוכחית לעיר של קלף כלשהו שנמצא בידו. כדי לבצע פעולה זו יש להשליך את הקלף המתאים לעיר שטסים אליה.
1. טיסת זכיון - `fly_charter` - מעבר מהעיר הנוכחית לעיר כלשהי. כדי לבצע פעולה זו יש להשליך את הקלף המתאים לעיר *שנמצאים בה*.
1. טיסת שאטל - `fly_shuttle` - אם בעיר הנוכחית ישנה תחנת-מחקר, אפשר לטוס לכל עיר אחרת שיש בה תחנת-מחקר. 
1. בנייה - `build` - בניית תחנת-מחקר בעיר שנמצאים בה. כדי לבצע פעולה זו יש להשליך את הקלף המתאים לעיר שנמצאים בה.
   * בכל עיר יכולה להיות לכל היותר תחנת-מחקר אחת. אם כבר יש תחנת מחקר בעיר הנוכחית, ומבצעים שוב פעולת "בנייה", אין צורך לזרוק חריגה, והקלף נשאר בידי השחקן.
1. גילוי תרופה - `discover_cure` - גילוי תרופה למחלה בצבע מסויים. כדי לבצע פעולה זו, יש להימצא בעיר שיש בה תחנת-מחקר, ולהשליך 5 קלפים בצבע של המחלה. צבע העיר שנמצאים בה לא משנה.
   * לכל מחלה יש תרופה אחת. אם כבר התגלתה תרופה למחלה, ומבצעים שוב פעולת "גילוי תרופה" לאותה מחלה, אין צורך לזרוק חריגה, והקלפים נשארים בידי השחקן.
1. טיפול במחלה - `treat` - הורדת קוביית-מחלה אחת מהעיר שנמצאים בה (הפחתת רמת המחלה ב-1).
   *  אם כבר התגלתה תרופה למחלה בצבע של העיר, אז פעולת "ריפוי מחלה" מורידה את כל קוביות המחלה מהעיר שנמצאים בה (הפחתת רמת המחלה ל-0).
   * אם אין בכלל זיהום בעיר (רמת המחלה היא 0), אז הפעולה תזרוק חריגה.

כל פעולה צריכה לעדכן את מצב הלוח ומיקום השחקן בהתאם.
אם הפעולה לא חוקית, יש לזרוק חריגה מתאימה.

בנוסף, יש לממש את השיטות הבאות:

*  `role` - פונקציה המחזירה את התפקיד של השחקן (ראו רשימת התפקידים למטה), לצורך תצוגה.
*  `take_card` - לקיחת קלף-עיר כלשהו. פעולה זו מדמה את התהליך שבו השחקן מקבל קלפים מהקופה בתחילת המשחק או במהלכו. 
   *   יש רק קלף אחד של כל עיר, ולכן אם מבצעים פעולת `take_card` על קלף שכבר נמצא בידי השחקן, לא יהיה כל שינוי במצב השחקן. 
   * אין צורך לבדוק את התקינות של שיטה זו. בפרט: אין צורך לבדוק שהקלף עדיין בקופה, או שלא נותנים קלף פעמיים, וכד'. השיטה תמיד מצליחה.
* `remove_cards` - הסרת כל הקלפים מידי השחקן. שיטה זו נועדה לבדיקות בלבד, היא תמיד מצליחה ואין צורך לבדוק אותה באופן מיוחד.

הערות:

* יכולים להיות שני שחקנים או יותר באותה עיר - לא קורה שום דבר מיוחד במצב זה.


## תפקידים

ישנם תפקידים שונים של שחקנים, שיש להם כישורים מיוחדים (הכישורים דומים אבל לא זהים למשחק המקורי):

1. קצין מבצעים - `OperationsExpert`:יכול לבצע פעולת "בנייה" בכל עיר שהוא נמצא בה, בלי להשליך קלף-עיר מתאים.
1. קצין תעבורה - `Dispatcher`: כשהוא נמצא בתחנת-מחקר, הוא יכול לבצע פעולת "טיסה ישירה" לכל עיר שהוא רוצה, ללא השלכת קלף-עיר.
1. מדענית - `Scientist`: יכולה לבצע פעולת "גילוי תרופה" בעזרת `n` קלפים בלבד (במקום 5), כאשר הפרמטר `n` מועבר בבנאי (במשחק המקורי `n=4`).
1. חוקרת - `Researcher`: יכולה לבצע פעולת "גילוי תרופה" בכל עיר - לא חייבת להיות בתחנת מחקר.
1. פראמדיק - `Medic`: כשהוא מבצע פעולת "טיפול במחלה", הוא מוריד את כל קוביות-המחלה מהעיר שהוא נמצא בה, ולא רק אחת.
   * אם כבר התגלתה תרופה למחלה, הוא אוטומטית מוריד את כל קוביות-המחלה מכל עיר שהוא נכנס אליה, גם בלי לבצע פעולת "טיפול במחלה".
1. וירולוגית - `Virologist`: יכולה לבצע פעולת "טיפול במחלה", לא רק בעיר  שהיא נמצאת בה, אלא בכל עיר בעולם - ע"י השלכת קלף של אותה העיר.
1. פורסת גנים - `GeneSplicer`: יכולה לבצע פעולת "גילוי תרופה" בעזרת 5 קלפים כלשהם - לא דווקא מהצבע של המחלה.
1. רופא שטח - `FieldDoctor`: יכול לבצע פעולת "טיפול במחלה" לא רק בעיר שהוא נמצא בה אלא בכל עיר סמוכה לעיר שהוא נמצא בה (ע"פ מפת הקשרים), בלי להשליך קלף עיר.

בשלב ב עליכם לכתוב מימוש מלא העובר את כל הבדיקות.
כיתבו את כל הקבצים הדרושים כך שהפקודות הבאות יעבדו ללא שגיאות:

<div dir='ltr'>

	make test1 && ./test1
	make test2 && ./test2
	make test3 && ./test3
	make tidy
	make valgrind

</div>

אין לשנות קבצים קיימים אלא רק להוסיף קבצים חדשים.

בנוסף, לצורך הצגה, יש לכתוב תוכנית ראשית יצירתית, המדגימה את כל הפעולות של הלוח והשחקנים השונים.

יש לפתור את המטלה באופן עצמאי.

* מותר להתייעץ עם סטודנטים אחרים או לחפש מידע באינטרנט;
אסור להעתיק קטעי-קוד שלמים מסטודנטים אחרים או מהאינטרנט.
* יש לדווח על כל עזרה שקיבלתם, מסטודנטים אחרים או מהאינטרנט, בהתאם ל[תקנון היושר של המחלקה](https://www.ariel.ac.il/wp/cs/wp-content/uploads/sites/88/2020/08/Guidelines-for-Academic-Integrity.pdf).


בהצלחה
</div>
