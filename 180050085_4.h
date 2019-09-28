#include<vector>
#include<iostream>

template <class T>
class myvector
{
      // declare variables that are needed. These are private to the class.
      int vsize;
      int vcapacity;
      int front, rear;
      std::vector<T> v;

      public:
     
      // define the methods    

      void push_front(T x)
      {
            if (vsize==0)
            {
                  v[front] = x;
                  vsize++;
            }
            else if(vsize<vcapacity)
            {
                  front = front-1;
                  if (front==-1)
                        front = vcapacity-1;

                  v[front]=x;
                  vsize++;
            }
            else
            {
                  std::vector<T> temp(vcapacity*2);
                  int i=front;
                  int index=vcapacity;
                  while(i!=rear)
                  {
                        temp[index] = v[i];
                        i=i+1;
                        index++;
                        if(i>=vcapacity)
                              i-=vcapacity;
                        if (index>=vcapacity*2)
                              index-=vcapacity*2;
                  }
                  temp[index] = v[rear];

                  // for (int i=0;i<temp.size();i++)
                  // {
                  //       std::cout<<temp[i]<<" ";
                  // }
                  // std::cout<<"\n";

                  rear = index;
                  
                  v = temp;

                  front = vcapacity-1;
                  vcapacity*=2;
                  v[front] = x;
                  vsize++;

                  // for (int i=0;i<v.size();i++)
                  // {
                  //       std::cout<<v[i]<<" ";
                  // }
                  // std::cout<<"\n"<<rear<<" "<<index<<" "<<front<<" "<<vcapacity<<" "<<vsize<<"\n";
            }
            // std::cout<<vsize<<endl;
      }
      void push_back(T x)
      {
            if (vsize==0)
            {
                  v[front] = x;
                  vsize++;
            }
            else if(vsize<vcapacity)
            {
                  rear=rear+1;
                  if (rear>=vcapacity)
                        rear-=vcapacity;
                  v[rear]=x;
                  vsize++;
            }
            else
            {
                  std::vector<T> temp(vcapacity*2);
                  int i=front;
                  int index = 0;
                  while(i!=rear)
                  {
                        temp[index] = v[i];
                        i=i+1;
                        index++;
                        if(i>=vcapacity)
                              i-=vcapacity;
                  }
                  temp[index] = v[rear];

                  v = temp;
                  front = 0;
                  rear = vcapacity;

                  v[rear] = x;
                  vsize++;
                  vcapacity*=2;
            }
            // std::cout<<vsize<<endl;     
      }
      void pop_front()
      {
            if (vsize==1)
            {
                  vsize--;
            }
            else if (vsize!=0)
            {
                  front = front+1;
                  if (front>=vcapacity)
                        front-=vcapacity;

                  vsize--;
            }
      }
      void pop_back()
      {
          if (vsize==1)
          {
                  vsize--;
          }
          else if (vsize!=0)
          {
                  rear = rear-1;
                  if (rear ==-1)
                        rear = vcapacity-1;

                  vsize--;
          }
      }
      int size() const{
      
            return vsize;
      }

      T & operator[](int i)
      {
            int var = front+i;
            if (var>vcapacity)
                  var-=vcapacity;

            if(i>=0 && i<vsize)
            {
                  return v[var];
            }
      }

      // You may also need to define a constructor for initialization;
      myvector<T>()
      {
            vcapacity = 2;
            vsize =0;
            front = 0;
            rear = 0;
            std::vector<T> temp(vcapacity);
            v = temp;
      }
};
