SELECT BOOK_ID, DATE_FORMAT(PUBLISHED_DATE, '%Y-%m-%d') AS PUBLISHED_DATE
FROM BOOK
WHERE CATEGORY LIKE '인문' AND DATE_FORMAT(PUBLISHED_DATE, '%Y') LIKE '2021'
ORDER BY PUBLISHED_DATE ASC;