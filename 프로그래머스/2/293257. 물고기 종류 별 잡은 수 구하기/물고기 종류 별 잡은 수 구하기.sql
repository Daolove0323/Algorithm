SELECT COUNT(*) FISH_COUNT, B.FISH_NAME
FROM FISH_INFO A JOIN FISH_NAME_INFO B ON A.FISH_TYPE=B.FISH_TYPE
GROUP BY B.FISH_NAME
ORDER BY FISH_COUNT DESC;