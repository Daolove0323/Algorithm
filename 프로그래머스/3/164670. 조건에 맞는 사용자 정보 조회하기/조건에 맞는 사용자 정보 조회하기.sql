SELECT DISTINCT B.USER_ID, B.NICKNAME,
CONCAT(B.CITY, ' ', B.STREET_ADDRESS1, ' ', B.STREET_ADDRESS2) 전체주소,
CONCAT(SUBSTR(B.TLNO, 1, 3), '-', SUBSTR(B.TLNO, 4, 4), '-', SUBSTR(B.TLNO, 8, 4)) 전화번호
FROM USED_GOODS_BOARD A JOIN USED_GOODS_USER B ON A.WRITER_ID=B.USER_ID
WHERE B.USER_ID IN (SELECT C.WRITER_ID
                    FROM USED_GOODS_BOARD C
                    GROUP BY C.WRITER_ID
                    HAVING COUNT(*) >= 3)
ORDER BY B.USER_ID DESC