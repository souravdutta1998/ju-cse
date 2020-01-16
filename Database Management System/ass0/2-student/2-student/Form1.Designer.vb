<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits _2_student.Main

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.addButton = New System.Windows.Forms.Button
        Me.searchButton = New System.Windows.Forms.Button
        Me.editButton = New System.Windows.Forms.Button
        Me.deleteButton = New System.Windows.Forms.Button
        Me.displayButton = New System.Windows.Forms.Button
        Me.SuspendLayout()
        '
        'addButton
        '
        Me.addButton.Location = New System.Drawing.Point(98, 90)
        Me.addButton.Name = "addButton"
        Me.addButton.Size = New System.Drawing.Size(99, 23)
        Me.addButton.TabIndex = 1
        Me.addButton.Text = "Add Student"
        Me.addButton.UseVisualStyleBackColor = True
        Me.addButton.UseWaitCursor = True
        '
        'searchButton
        '
        Me.searchButton.Location = New System.Drawing.Point(98, 120)
        Me.searchButton.Name = "searchButton"
        Me.searchButton.Size = New System.Drawing.Size(99, 23)
        Me.searchButton.TabIndex = 2
        Me.searchButton.Text = "Search Student"
        Me.searchButton.UseVisualStyleBackColor = True
        '
        'editButton
        '
        Me.editButton.Location = New System.Drawing.Point(98, 150)
        Me.editButton.Name = "editButton"
        Me.editButton.Size = New System.Drawing.Size(99, 23)
        Me.editButton.TabIndex = 3
        Me.editButton.Text = "Edit Student"
        Me.editButton.UseVisualStyleBackColor = True
        '
        'deleteButton
        '
        Me.deleteButton.Location = New System.Drawing.Point(98, 180)
        Me.deleteButton.Name = "deleteButton"
        Me.deleteButton.Size = New System.Drawing.Size(99, 23)
        Me.deleteButton.TabIndex = 4
        Me.deleteButton.Text = "Delete Student"
        Me.deleteButton.UseVisualStyleBackColor = True
        '
        'displayButton
        '
        Me.displayButton.Location = New System.Drawing.Point(98, 210)
        Me.displayButton.Name = "displayButton"
        Me.displayButton.Size = New System.Drawing.Size(99, 23)
        Me.displayButton.TabIndex = 5
        Me.displayButton.Text = "Display Student"
        Me.displayButton.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(292, 273)
        Me.Controls.Add(Me.displayButton)
        Me.Controls.Add(Me.deleteButton)
        Me.Controls.Add(Me.editButton)
        Me.Controls.Add(Me.searchButton)
        Me.Controls.Add(Me.addButton)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents addButton As System.Windows.Forms.Button
    Friend WithEvents searchButton As System.Windows.Forms.Button
    Friend WithEvents editButton As System.Windows.Forms.Button
    Friend WithEvents deleteButton As System.Windows.Forms.Button
    Friend WithEvents displayButton As System.Windows.Forms.Button

End Class
