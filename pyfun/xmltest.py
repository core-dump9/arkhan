import xml.etree.cElementTree as et;

sxml=open("xmlclass.xml", "r").read();
tree=et.fromstring(sxml)

for el in tree.findall('first'):
    print '-------------------';
    for ch in el.getchildren():
        print ch.tag, ch.text#'{:>15}: {:<30}'.format(ch.tag, ch.text);