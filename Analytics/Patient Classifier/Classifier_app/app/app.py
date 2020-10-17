# coding: utf-8
from flask import Flask, render_template, request
app = Flask(__name__)
@app.route('/send', methods=['GET','POST'])
def send():
        if request.method == 'POST':
                age1 = request.form['age']
                morphology1 = request.form['Morphology']
                sex1 = request.form['Sex']
                tumourcount1 = request.form['Tumour']
               # res=compute(age1,morphology1,sex1,tumourcount1)
               # In[1]:
                import pandas as pd
                ds = pd.read_csv('../dataset/Epidemiology_of_lung_cancer_tumours_in_England_2009_to_2013.csv')
                # In[2]:
                ds.columns = ['tumourcount', 'sex', 'age', 'codeath', 'ethnicity', 'yodiagnosis', 'morphology', 'yodeath']
                # In[3]:
                ds['span']=ds.yodeath-ds.yodiagnosis
                ds=ds[['age','sex','ethnicity','morphology','tumourcount','codeath','span']] #'yodiagnosis','yodeath',
                for i in range(0,ds.age.size):
                    if(type(ds.age[i])==type('nik')):
                        ds.loc[i,'age']=int(ds.loc[i,'age'][0:2])
                # In[4]:
                ds=ds.loc[ds['tumourcount']>10]
                ds=ds.dropna(how='any')
                ds.loc[ds['span']>=1,'span']=1
                #mor = [85503, 82463, 85603, 82503]
                ds.span.value_counts()
                # In[19]:
                x=ds.iloc[:,[0,1,3,4]]
                y=ds.iloc[:,6]
                xfull=x;
                yfull=y;
                # In[13]:
                Sage=age1                       # input("Age");
                if(sex1=='Male'):
                    Ssex=1                       # input("Sex (1 - Male | 2 -  Female) :")
                else:
                    Ssex=2
                Smorphology=morphology1             # input("Morphology (8****) :");
                Stumourcount=tumourcount1           # input("Tumour count : ");
                a=[(Sage,Ssex,Smorphology,Stumourcount)]
                Sample=pd.DataFrame(a)
                # In[14]:
                from sklearn.svm import SVC
                svm = SVC(kernel='linear')
                svm.fit(xfull,yfull)
                # In[15]:
                res=svm.predict(Sample)
                if(res[0]):
                    #return("Most likely")
                    re = "Survival rate of the patient is relatively over an year"    
                else:
                    #return("Less likely")
                    re = "Survival rate of the patient is relatively less than one year"
                return render_template('age.html', re=re)
        return render_template('index.html')
if __name__=="__main__":
        app.run()







