SELECT CATEGORY, PRICE, PRODUCT_NAME
FROM FOOD_PRODUCT
WHERE (CATEGORY, PRICE) in (SELECT CATEGORY, MAX(PRICE)
                            FROM FOOD_PRODUCT
                            GROUP BY CATEGORY) AND
                            CATEGORY IN ('과자', '국', '김치', '식용유')
ORDER BY PRICE DESC;