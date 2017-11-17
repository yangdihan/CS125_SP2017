/**
 * @author dyang42
 *
 */
public class Person
{
private final String name;
private final int age;
private final char gender;
private final Person child1; //left child
private final Person child2; //right child

public Person(String name, int age, char gender, Person c1, Person c2)
{
    this.name=name;
    this.age=age;
    this.gender=gender;
    this.child1 = c1;
    this.child2 = c2;
}

public String toString()
{
    return name+"*"+age+"*"+gender;
}

public String getName() 
{
	return name;
}

public int getAge() 
{
	return age;
}

public char getGender() 
{
	return gender;
}

public boolean equals(Person p)
{
	return (this.name.equals(p.name)) &&
			(this.age==p.age) &&
			(this.gender==p.gender);
}


public void print() 
{
   System.out.println(this);
   if(child1 != null)
       child1.print();
   if(child2 != null)
       child2.print();
   
}

public int count() // total person count including this object
{
	if (this.child1 == null && this.child2 == null)
		return 1;
	else if (this.child1 == null || this.child2 == null)
		return 2;
	else
		return 1 + this.child1.count() + this.child2.count();
}

public int countChildren(){
	if(this.child1 == null && this.child2 == null)
		return 0;
	else if (this.child1 == null || this.child2 == null)
		return 1;
	else
		return 2;
}
public int countGrandChildren() // but not greatGrandChildren
{
	if (this.child1 == null && this.child2 == null)
		return 0;
	else if (this.child1 == null && this.child2 != null)
		return this.child2.countChildren();
	else if (this.child1 != null && this.child2 == null)
		return this.child1.countChildren();
	else
		return this.child1.countChildren() + this.child2.countChildren();	
}

public int countMaxGenerations()
{
	if (this.child1 == null && this.child2 == null)
		return 1;
	else if (this.child1 == null)
		return 1+this.child2.countMaxGenerations();
	else if (this.child2 == null)
		return 1+this.child1.countMaxGenerations();
	else if (this.child1.countMaxGenerations() > this.child2.countMaxGenerations())
		return 1+this.child1.countMaxGenerations();
	else
		return 1+this.child2.countMaxGenerations();
}

public int countGender(char gen)
{
	int count = 0;
	if (this.gender == gen)
		count += 1;
	if (this.child1 != null)
		count += this.child1.countGender(gen);
	if (this.child2 != null)
		count += this.child2.countGender(gen);
	return count;
}


public Person search(String name, int maxGeneration)
{
	Person result = null;
	if (maxGeneration == 0){
		result = null;
		return result;
	}
	if (this.name.equals(name)){
		result = this;
		return result;
	}
	if (this.child1 != null){
		result = this.child1.search(name, maxGeneration-1);
		if (result!= null)
			return result;
	}
	if (this.child2 != null){
		result = this.child2.search(name, maxGeneration-1);
		if (result!= null)
			return result;
	}
	return result;
}


} // end of class