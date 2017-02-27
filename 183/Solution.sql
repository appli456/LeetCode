SELECT A.Name AS Customers FROM Customers A LEFT JOIN Orders B ON A.Id=B.CustomerId
WHERE B.CustomerId is NULL;