SELECT a.dept_id, dept_name_en, round(avg(SAL), 0) avg_sal
FROM hr_department a JOIN hr_employees b ON a.dept_id=b.dept_id
GROUP BY dept_id
order by avg_sal desc;