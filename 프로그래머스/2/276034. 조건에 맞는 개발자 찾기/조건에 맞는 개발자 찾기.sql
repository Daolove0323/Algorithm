SELECT id, email, first_name, last_name
FROM developers
WHERE skill_code & (SELECT sum(code)
                   FROM skillcodes
                   WHERE name in ('C#', 'Python'))
ORDER BY id