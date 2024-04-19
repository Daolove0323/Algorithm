SELECT id, name, a.host_id
FROM places a JOIN (SELECT host_id, COUNT(*) count
                  FROM places
                  GROUP By host_id) b
                  ON a.host_id=b.host_id
WHERE count >= 2
ORDER BY id