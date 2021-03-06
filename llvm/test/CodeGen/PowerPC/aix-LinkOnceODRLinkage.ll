; RUN: llc -mtriple powerpc-ibm-aix-xcoff < %s | \
; RUN: FileCheck %s

; RUN: llc -mtriple powerpc64-ibm-aix-xcoff < %s | \
; RUN: FileCheck %s

define linkonce_odr void @_Z3fooIiEvT_() {
entry:
  ret void
}

; CHECK: .weak   _Z3fooIiEvT_
; CHECK: .weak   ._Z3fooIiEvT_
