class Employee:
   'Common base class for all employees'
   _empCount = 0

   def __init__(self, name, salary):
      self.name = name
      self.salary = salary
      Employee._empCount += 1
   
   def displayCount(self):
     return Employee._empCount

   def displayEmployee(self):
      print "Name : ", self.name,  ", Salary: ", self.salary
"""
emp1 = Employee("Henry", 50000);
#emp1.displayEmployee();
emp1.age = 20;
emp1.displayEmployee();
print "Age : %d" % emp1.age;
emp2 = Employee("Damilola", 45900);
emp2.age = 21;
emp2.displayEmployee();
print Employee._empCount;

"""